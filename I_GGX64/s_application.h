
#if !defined(APPLICATION_H_INCLUDED)
#define APPLICATION_H_INCLUDED


class Application {

	Application();
	Application(const Application&);

public:
	static void initialize();
	static void free_resources();
	static void exit_with_failure();
};

#endif