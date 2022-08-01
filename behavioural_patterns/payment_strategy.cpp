// Strategy Pattern
#include <iostream>
#include <string>

using namespace std;

class PaymentRequestFormater {
 public:
  static string formatPaymentRequest(string payment_service_name,
                                     string clientID, string amount) {
    return "PAYMENT SERVICE: " + payment_service_name +
           ", CLIENT_ID: " + clientID + ", AMOUNT: " + amount;
  }
};

class PaymentService {
 public:
  virtual void sendPaymentRequest(string clientID, string amount) = 0;
};

class PixPaymentService : public PaymentService {
  string service_name = "PIX";

 public:
  void sendPaymentRequest(string clientID, string amount) override {
    cout << PaymentRequestFormater::formatPaymentRequest(service_name, clientID,
                                                         amount)
         << endl;
    cout << "QR Code generated" << endl;
  }
};

class CreditCardPaymentService : public PaymentService {
  string service_name = "CreditCard";

 public:
  void sendPaymentRequest(string clientID, string amount) override {
    cout << PaymentRequestFormater::formatPaymentRequest(service_name, clientID,
                                                         amount)
         << endl;
  }
};

class PaymentAPI {
  string client_id;
  string amount;
  PaymentService* payment_service;

 public:
  void pay() { payment_service->sendPaymentRequest(client_id, amount); };
  void setPaymentService(PaymentService* service) { payment_service = service; }
  void setClientID(string client_id) { this->client_id = client_id; }
  void setAmount(string amount) { this->amount = amount; }
};

int main() {
  PaymentAPI payment_api;
  PixPaymentService pix_payment_service;
  CreditCardPaymentService credit_car_payment_service;
  payment_api.setClientID("1234");
  payment_api.setAmount("10.00");
  payment_api.setPaymentService(&pix_payment_service);
  payment_api.pay();
  payment_api.setClientID("5678");
  payment_api.setAmount("15.00");
  payment_api.setPaymentService(&credit_car_payment_service);
  payment_api.pay();
  return 0;
}