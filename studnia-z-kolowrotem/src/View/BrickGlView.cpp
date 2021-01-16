#include "BrickGlView.h"

#include "Model/BrickGlModel.h"

struct BrickGlView::State {
	State() : buffer{0} {
		glGenBuffers(1, &buffer);
		glBindBuffer(GL_ARRAY_BUFFER, buffer);

		glGenBuffers(1, &elementBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
	}

	State(const BrickGlModel& model) : State() {
		bindModel(model);
	}
	
	~State() {
		glDeleteBuffers(1, &elementBuffer);
		glDeleteBuffers(1, &buffer);
	}
	
	State(const State&) = delete;
	State& operator=(const State&) = delete;

	void bindModel(const BrickGlModel& newModel) {
		auto& vertices = newModel.getVertexArray();
		glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * vertices.size(), vertices.data(), GL_STATIC_DRAW);
		
		auto& indices = BrickGlModel::INDEX_ARRAY;
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indices.size(), indices.data(), GL_STATIC_DRAW);
	}

	void draw() const {
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glDrawElements(GL_TRIANGLES, BrickGlModel::INDEX_ARRAY.size(), GL_UNSIGNED_INT, nullptr);
		glDisableVertexAttribArray(0);
	}

	GLuint buffer;
	GLuint elementBuffer;
};

BrickGlView::BrickGlView()
	: state{std::make_unique<State>()} { }

BrickGlView::BrickGlView(const BrickGlModel& model) : BrickGlView() {
	setModel(model);
}

BrickGlView::~BrickGlView() = default;

void BrickGlView::setModel(const BrickGlModel& newModel) {
	state->bindModel(newModel);
}

void BrickGlView::draw() const {
	state->draw();
}
