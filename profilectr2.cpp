#include "profilectr.hpp"

using namespace eosio;

[[eosio::action]]
void profilectr::userinsert(name user, std::string display_name, std::string about_me, address_t location, std::string img, std::vector<language_t> languages, std::vector<platform_t> platforms) {
    
    require_auth( user );

    // Argument Checks
    eosio::check( display_name.size() <= MAX_DISPLAY_NAME_SIZE, "display name is too long. MAX_DISPLAY_NAME_SIZE= 30");
    eosio::check( display_name.size() == 0 || display_name.size() >= MIN_DISPLAY_NAME_SIZE, "display name is too long. MIN_DISPLAY_NAME_SIZE= 3");
    eosio::check( about_me.size() <= MAX_ABOUTME_SIZE, "'about me' is too long. MAX_IPFS_SIZE=46");
    eosio::check( about_me.size() == 0 || about_me.size() >= MIN_ABOUTME_SIZE, "display name is too long. MIN_DISPLAY_NAME_SIZE= 3");
    eosio::check( img.size() <= MAX_IMG_SIZE, "Image is too large. MAX_IMG_SIZE = 400 characters");
    eosio::check( location.country.size() <= MAX_COUNTRY_SIZE, "country code max size is 4 characters");
    // Check language codes
    for(int i=0; i<languages.size(); ++i) {
        eosio::check( languages[i].lang_code.size() <= MAX_LANG_CODE_SIZE, "lang code max size is 8 bytes");
        eosio::check( languages[i].lang_code.size() >= MIN_LANG_CODE_SIZE, "lang code must be at least 2 characters");
        eosio::check( languages[i].level >=0 && languages[i].level <= 3, "language level must be between 0 and 3");
    }
    // Check platforms
    for(int i=0; i<platforms.size(); ++i) {
        eosio::check( platforms[i].platform.size() <= MAX_PLATFORM_SIZE, "platform max size is 20 characters");
        eosio::check( platforms[i].platform.size() >= MIN_PLATFORM_SIZE, "platform size must be at least 4 characters");
    }
    
}

[[eosio::action]]
void profilectr::create(name author, name category, name owner, std::string idata, std::string mdata) {
    bool requireclaim = false;
    action(
        permission_level{ get_self(), "active"_n },
        SIMPLEASSETSCONTRACT, "create"_n,
        std::make_tuple(author, category, owner, idata, mdata, requireclaim)
    ).send();
    //SimpleAssets::create_action create("simpleassets"_n, { get_self(), "active"_n });
    //create.send(author, category, owner, idata, mdata, requireclaim);
}

[[eosio::action]]
void profilectr::claim(name claimer, std::vector< uint64_t >& assetids) {
    // action(
    //     permission_level{ get_self(), "active"_n },
    //     SIMPLEASSETSCONTRACT, "claim"_n,
    //     std::make_tuple(claimer, assetids)
    // ).send();
}

[[eosio::action]]
void profilectr::transfer(name from, name to, std::vector< uint64_t >& assetids, std::string memo) {
    // if (assetids.size() == 1) {
    //     memo = std::string("Transfer one asset");
    // }
    // else {
    //     memo = std::string("Transfer more than one asset");
    // }
    // action(
    //     permission_level{ get_self(), "active"_n },
    //     SIMPLEASSETSCONTRACT, "transfer"_n,
    //     std::make_tuple(from, to, assetids, memo)
    // ).send();
}

[[eosio::action]]
void profilectr::offer(name owner, name newowner, std::vector< uint64_t >& assetids, std::string memo) {
    // if (assetids.size() == 1) {
    //     memo = std::string("Offer one asset");
    // }
    // else {
    //     memo = std::string("Offer more than one asset");
    // }
    // action(
    //     permission_level{ get_self(), "active"_n },
    //     SIMPLEASSETSCONTRACT, "offer"_n,
    //     std::make_tuple(owner, newowner, assetids, memo)
    // ).send();
}

[[eosio::action]]
void profilectr::canceloffer(name owner, std::vector< uint64_t >& assetids) {
    // action(
    //     permission_level{ get_self(), "active"_n },
    //     SIMPLEASSETSCONTRACT, "canceloffer",
    //     std::make_tuple(owner, assetids)
    // ).send();
}

[[eosio::action]]
void profilectr::delegate(name owner, name to, std::vector< uint64_t >& assetids, uint64_t period, std::string memo) {
    // action( 
    //     permission_level{ get_self(), "active"_n },
    //     SIMPLEASSETSCONTRACT, "delegate"_n,
    //     std::make_tuple(owner, to, assetids, period, memo)
    // ).send();
}

[[eosio::action]]
void profilectr::undelegate(name owner, name from, std::vector< uint64_t >& assetids) {
    // action(
    //     permission_level{ get_self(), "active"_n },
    //     SIMPLEASSETSCONTRACT, "undelegate"_n,
    //     std::make_tuple(owner, from, assetids)
    // ).send();
}

//EOSIO_DISPATCH( profilectr, ( userinsert )() create )( claim )( transfer )( offer )( canceloffer )( delegate )( undelegate ) )

