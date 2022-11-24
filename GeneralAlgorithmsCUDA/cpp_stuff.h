#pragma once

#define NO_COPY_CLASS(class_name) \
	class_name(const class_name&) = delete; \
	class_name(class_name&&) = delete; \
	class_name& operator=(const class_name&) = delete; \
	class_name& operator=(class_name&&) = delete \

#define MOVE_ONLY_CLASS(class_name) \
	class_name(const class_name&) = delete; \
	class_name& operator=(const class_name&) = delete; \

template<typename... Ts>
struct Overload : Ts... {
	using Ts::operator() ...;
};
template<class... Ts> Overload(Ts...)->Overload<Ts...>;
