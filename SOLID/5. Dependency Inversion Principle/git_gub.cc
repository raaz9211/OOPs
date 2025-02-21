#include <iostream>
using namespace std;

// Interface for version control system
class IVersionControl
{
public:
    virtual void commit(const std::string &message) = 0;
    virtual void push() = 0;
    virtual void pull() = 0;
};

// Git version control implementation
class GitVersionControl : public IVersionControl
{
public:
    void commit(const std::string &message) override
    {
        std::cout << "Committing changes to Git with message: " << message << std::endl;
    }

    void push() override
    {
        std::cout << "Pushing changes to remote Git repository." << std::endl;
    }

    void pull() override
    {
        std::cout << "Pulling changes from remote Git repository." << std::endl;
    }
};

// Raj Git version control implementation
class RajGitVersionControl : public IVersionControl
{
public:
    void commit(const std::string &message) override
    {
        std::cout << "Committing changes to RajGit with message: " << message << std::endl;
    }

    void push() override
    {
        std::cout << "Pushing changes to remote RajGit repository." << std::endl;
    }

    void pull() override
    {
        std::cout << "Pulling changes from remote RajGit repository." << std::endl;
    }

};

// Team class that relies on version control
class DevelopmentTeam
{
private:
    IVersionControl *versionControl;

public:
    DevelopmentTeam(IVersionControl *vc) : versionControl(vc) {} // [Dependency Inversion] it can work with any version control implementation that adheres to the interface.

    void makeCommit(const std::string &message)
    {
        versionControl->commit(message);
    }

    void performPush()
    {
        versionControl->push();
    }

    void performPull()
    {
        versionControl->pull();
    }
};

int main(){
    GitVersionControl gitVersionControl;
    RajGitVersionControl rajGitVersionControl;
    
    DevelopmentTeam team1(&gitVersionControl);
    team1.makeCommit("Initial commit");
    team1.performPush();
    team1.performPull();

    DevelopmentTeam team2(&rajGitVersionControl);
    team2.makeCommit("Initial commit");
    team2.performPush();
    team2.performPull();

}