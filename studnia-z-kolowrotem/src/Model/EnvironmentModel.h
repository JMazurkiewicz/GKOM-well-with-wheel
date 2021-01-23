#pragma once

class EnvironmentModel {
public:
	static constexpr float DEFAULT_SIZE = 10.0f;

	EnvironmentModel();
	EnvironmentModel(const EnvironmentModel&) = delete;
	EnvironmentModel& operator=(const EnvironmentModel&) = delete;

	float getSize() const noexcept;
	void setSize(float newSize);

	bool validateModel() const;

private:
	float size;
};
