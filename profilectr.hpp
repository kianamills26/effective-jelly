#include <eosio/eosio.hpp>
#include <eosio/print.hpp>
#include <eosio/asset.hpp>
//#include "SimpleAssets.hpp"
#include <ctime>
#include <vector>

using namespace eosio;

// Constants
// const name NFT_CONTRACT = name("eosio.nft")
// constexpr name SIMPLEASSETSCONTRACT = name(std::string_view("simpl1assets"));
const name SIMPLEASSETSCONTRACT = name("simpleassets");
const uint64_t MAX_IMG_SIZE = 400;
const uint64_t MAX_ABOUTME_SIZE = 300;
const uint64_t MIN_ABOUTME_SIZE = 3;
const uint64_t MAX_LANG_CODE_SIZE = 7;
const uint64_t MIN_LANG_CODE_SIZE = 2;
const uint64_t MAX_PLATFORM_SIZE = 20;
const uint64_t MIN_PLATFORM_SIZE = 4;
const uint64_t MAX_COUNTRY_SIZE = 4;
const uint64_t MIN_COUNTRY_SIZE = 1;
const uint64_t MAX_DISPLAY_NAME_SIZE = 30;
const uint64_t MIN_DISPLAY_NAME_SIZE = 3;

typedef struct address{
    std::string city;
    std::string state;
    std::string country;
} address_t;

typedef struct language{
    std::string lang_code;
    int level; // 0-3
} language_t;

typedef struct platform{
    std::string platform;
    std::string url;
} platform_t;

class [[eosio::contract("profilectr")]] profilectr: public eosio::contract {
public:
    
    profilectr( name receiver, name code, datastream<const char*> ds ) : contract(receiver, code, ds) {}
    
    // ABI FUNCTIONS
    [[eosio::action]]
    void userinsert(name user,
                std::string display_name,
                std::string about_me,
                address_t location,
                std::string img,
                std::vector<language_t> languages,
                std::vector<platform_t> platforms);

    /* Create a new asset
    * @param author
    * @param category is the category of the asset (allowed to change mdata)
    * @param owner is the owner of the asset
    * @param idata is immutable asset data
    * @param mdata is mutable asser data
    */
    [[eosio::action]]
    void create(name author, 
                name category, 
                name owner, 
                std::string idata, 
                std::string mdata);

    /* Claim one or more assets
    * @param claimer is account claiming the asset
    * @param assetids is array
    * @return no return value
    */
    [[eosio::action]]
    void claim(name claimer, 
                std::vector< uint64_t >& assetids);

    /* Transfer one or more assets
    * @param from is account who sends the asset.
    * @param to is account of receiver.
	* @param assetids is array of assetid's to transfer.
	* @param memo is transfers comment.
    */
    [[eosio::action]]
    void transfer(name from,
                name to,
                std::vector< uint64_t >& assetids,
                std::string memo);
   
   /* Offer asset for claim
   * @param owner is the owner of the asset
   * @param newowner is the future owner of the asset
   * @param assetids is array of assetids to offer
   * @param memo is memo for offer action
   */
   [[eosio::action]]
   void offer(name owner, 
                name newowner, 
                std::vector< uint64_t >& assetids,
                std::string memo);

    /* Cancel offer 
    * @param owner is the current owner of the asset
    * @param assetids array of assetids to cancel from offer
    */
   [[eosio::action]]
   void canceloffer(name owner,
                std::vector< uint64_t >& assetids);

    /* Delegates assets to {{to}} account
    * @param owner is the owner of the asset
    * @param to is borrower account name
    * @param assettids is the array of assetids to delegate
    * @param period is the time in seconds that the asset will be lent for
    * @param memo is memo for delegate action
    */
    [[eosio::action]]
    void delegate(name owner,
                name to,
                std::vector< uint64_t >& assetids,
                uint64_t period,
                std::string memo);

    /* Undelegates assets from {{from}} account
    * @param owner is the account of real owner of the asset
    * @param from is current account owner
    * @param assettids is the array of assetids to undelegate
    */
    [[eosio::action]]
    void undelegate(name owner,
                name from,
                std::vector< uint64_t > & assetids);

   // Don't need add_balance and sub_balance !


};
