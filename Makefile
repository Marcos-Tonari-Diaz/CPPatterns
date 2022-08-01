BEHAVIOURAL_PATH := behavioural_patterns
CREATIONAL_PATH := creational_patterns

shape_factory: $(CREATIONAL_PATH)/shape_factory.cpp
	g++ $(CREATIONAL_PATH)/shape_factory.cpp -o $(CREATIONAL_PATH)/shape_factory.out

singleton_log: $(CREATIONAL_PATH)/singleton_log.cpp
	g++ $(CREATIONAL_PATH)/singleton_log.cpp -o $(CREATIONAL_PATH)/singleton_log.out

log_observer: $(BEHAVIOURAL_PATH)/log_observer.cpp
	g++ $(BEHAVIOURAL_PATH)/log_observer.cpp -o $(BEHAVIOURAL_PATH)/log_observer.out

payment_strategy: $(BEHAVIOURAL_PATH)/payment_strategy.cpp
	g++ $(BEHAVIOURAL_PATH)/payment_strategy.cpp -o $(BEHAVIOURAL_PATH)/payment_strategy.out

all: shape_factory singleton_log log_observer payment_strategy

clean: 
	rm $(CREATIONAL_PATH)/*.out
	rm $(BEHAVIOURAL_PATH)/*.out