#include <releax>

using namespace std;

int check_func(releax::cli& app){
    bool force = false;

    cout << "Check function is working" << endl;

    if (app.is_flagset("f") || app.is_flagset("force")) {
        cout << "force flag set" << endl;
    }

    return 0;
}

int update_func(releax::cli& app){
    cout << "Update function is working" << endl;

    return 0;
}


int main(int ac, char** av)
{
    releax::cli app;

    app.name("sys-update")
       .version(0.1)
       .release('a')
       .description("a new alternative sys-update")
       .author("Pratyush Ratan", "ratan.pratyush@gmail.com", "-")
       .sub("update", "To update sys-update", "force-type|backup-loc|restore-point", update_func)
       .sub("check", "To check something", "url|release", check_func);


    return app.execute(ac, av);
}
