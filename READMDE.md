# Decentralized Profile
### Everipedia 
Git: https://github.com/EveripediaNetwork 

------------------------------------
## RAM usage 
The RAM usage for NFTs depends on how much data is stored in the idata and mdata fields.  If they both empty, each NFT takes up `276 bytes`.

Each symbol in imdata and mdata is +1 byte.

-------------------------------------
# Contract Actions

```
userinsert      (user, display_name, about_me, location, img, languages, platforms)
```

## NFT storage and transfer using SimpleAssets standard:
Git: https://github.com/CryptoLions/SimpleAssets

```
# -- For Storing and Transferring Non-Fungible Tokens (NFTs)---

 create			(author, category, owner, idata, mdata, requireсlaim)  
 transfer		(from, to , [assetid1,..,assetidn], memo)  
 
 offer			(owner, newowner, [assetid1,..,assetidn], memo)  
 canceloffer		(owner, [assetid1,..,assetidn])  
 claim			(claimer, [assetid1,..,assetidn])  
  
 delegate		(owner, to, [assetid1,..,assetidn], period, memo)  
 undelegate		(owner, from, [assetid1,..,assetidn]) 

 ```