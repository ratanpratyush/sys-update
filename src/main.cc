#include <releax>
#include <releax-cc/net>

using namespace std;

int main_func(releax::cli& app)
{
    releax::curl downloader;

    string url = "https://releax.in";
    string content;
    string header;

    downloader.url(url)
              .content(content)
              .header(header);

    long resp = downloader.perform();

    if (!downloader.good) {
        cout << "error while fetching " << url << endl;
        cout << "status code: " << resp << endl;
        cout << "header: " << header << endl; 

        return -2;
    }

    cout << "header: " << header << endl;
    cout << "Content: " << content << endl;

}

int check_func(releax::cli& app){
    bool force = false;

    string url = "https://releax.in";

    string cus_url = app.val_of_arg("url");

    if (len(cus_url) == 0)
    cus_url = url;
    else
    url = cus_url;

    
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