#include <releax>

using namespace std;

int main_func(releax::cli& app)
{
    if (app.is_flagset("force")) {

    }

    if (app.is_flagset("r")){

    }

    return 0;

}

int check_func(string url, string release){
    cout << "Check function is working" << endl;

}

int update_func(int force_type, int backup_loc, int restore_point){
    cout << "Update function is working" << endl;

}


int main(int ac, char** av)
{
    releax::cli app;

    app.name("sys-update")
       .version(0.1)
       .release('a')
       .description("a new alternative sys-update")
       .author("Pratyush Ratan", "ratan.pratyush@gmail.com", "-")
       .sub("update", "To update sys-update", "force-type", "backup-loc", "restore-point", update_func)
       .sub("check", "To check something", "url", "release", check_func)
       .main(main_func);


    return app.execute(ac, av);
}
