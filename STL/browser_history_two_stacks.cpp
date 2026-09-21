#include <iostream>
#include <stack>
#include <string>

using namespace std;

class BrowserHistory {
private:
    string currentPage;
    stack<string> backStack;
    stack<string> forwardStack;

public:
    explicit BrowserHistory(const string& homePage)
        : currentPage(homePage) {}

    void visit(const string& page) {
        // The current page becomes available through the Back operation.
        backStack.push(currentPage);
        currentPage = page;

        // A new visit starts a new path, so forward history is discarded.
        while (!forwardStack.empty()) {
            forwardStack.pop();
        }
    }

    void back() {
        if (backStack.empty()) {
            cout << "Cannot go back.\n";
            return;
        }

        // Save the current page so it can be restored with Forward.
        forwardStack.push(currentPage);
        currentPage = backStack.top();
        backStack.pop();
    }

    void forward() {
        if (forwardStack.empty()) {
            cout << "Cannot go forward.\n";
            return;
        }

        // Save the current page so it can be revisited with Back.
        backStack.push(currentPage);
        currentPage = forwardStack.top();
        forwardStack.pop();
    }

    void showCurrentPage() const {
        cout << "Current page: " << currentPage << '\n';
    }
};

int main() {
    BrowserHistory history("home.com");

    history.visit("news.com");
    history.visit("example.com");
    history.showCurrentPage();

    history.back();
    history.showCurrentPage();

    history.back();
    history.showCurrentPage();

    history.forward();
    history.showCurrentPage();

    history.visit("school.com");
    history.showCurrentPage();

    // Forward history was cleared by the new visit.
    history.forward();

    return 0;
}
