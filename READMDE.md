# profilectr

# Contract Actions

```
userinsert(user, display_name, about_me, location, img, languages, platforms)
```

## NFT storage and transfer rom SimpleAssets standard:
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