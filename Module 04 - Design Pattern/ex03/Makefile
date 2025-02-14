NAME = mediator
DEBUG = mediator_debug
SRC = src/main.cpp \
			src/Classroom.cpp \
			src/Course.cpp \
			src/CourseFinishedForm.cpp \
			src/Courtyard.cpp \
			src/Form.cpp \
			src/Headmaster.cpp \
			src/HeadmasterOffice.cpp \
			src/NeedCourseCreationForm.cpp \
			src/NeedMoreClassRoomForm.cpp \
			src/Person.cpp \
			src/Professor.cpp \
			src/Room.cpp \
			src/SecretarialOffice.cpp \
			src/Secretary.cpp \
			src/Staff.cpp \
			src/StaffRestRoom.cpp \
			src/Student.cpp \
			src/SubscriptionToCourseForm.cpp

CC = @c++
CFLAGS = -Wall -Wextra -Werror -pedantic -Wshadow -std=c++14
CFLAGS_DEBUG = -Wall -Wextra -Werror -pedantic -Wshadow -std=c++14 -g -fsanitize=address,undefined

all:			$(NAME)

$(NAME):	$(SRC)
					$(CC) $(CFLAGS) $^ -o $@

debug:		$(DEBUG)

$(DEBUG):	$(SRC)
					$(CC) $(CFLAGS_DEBUG) $^ -o $@

clean:

fclean:
					@rm -rf $(NAME) $(DEBUG)

re:				fclean all

re_debug:	fclean debug

PHONY: all debug clean fclean re re_debug