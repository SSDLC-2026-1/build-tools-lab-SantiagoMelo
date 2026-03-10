#include "validator.h"
#include <regex>

using namespace std;

vector<string> validateTicket(const Ticket& ticket) {

    vector<string> errors;

    regex codePattern("^TK\\d{3}$");

    if (ticket.code.empty()) {
        errors.push_back("Empty ticket code");
    }
    else if (!regex_match(ticket.code, codePattern)) {
        errors.push_back("Invalid ticket code format");
    }

    if (ticket.type != "general" && ticket.type != "vip" && ticket.type != "student") {
        errors.push_back("Invalid ticket type");
    }

    if (ticket.status != "active" && ticket.status != "used" && ticket.status != "cancelled") {
        errors.push_back("Invalid ticket status");
    }

    if (ticket.status != "active") {
        errors.push_back("Ticket is not active");
    }

    int number = stoi(ticket.code.substr(2));
    if (ticket.type == "vip" && number <= 500) {
        errors.push_back("VIP tickets must have code greater than TK500");
    }

    return errors;
}