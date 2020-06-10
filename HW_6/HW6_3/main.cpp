#include"gechatuser.h"
int main(){
    shared_ptr<GechatUser> gzw (new GechatUser("GeziWang"));
    shared_ptr<GechatUser> gf(new GechatUser("Girlfriend"));
    shared_ptr<GechatUser> chc(new GechatUser("Caohch"));
    shared_ptr<GechatUser> xcb(new GechatUser("Zhaman XCB"));
    gzw->addFriend(gf);
    gf->addFriend(gzw);
    xcb->addFriend(gf);
    gf->addFriend(xcb);
    gzw->addFriend(chc);
    //gf->singleDelete(gzw);
    //gzw->singleDelete(gf);
    //gf->singleDelete("GeziWang");
    //gzw->singleDelete("Girlfriend");
    //gf->doubleDelete(gzw);
    gf->doubleDelete("GeziWang");
    CustomSet<GechatUser> sad_story;
    sad_story.add(*gzw);
    sad_story.add(*gf);
    sad_story.printSet();
}