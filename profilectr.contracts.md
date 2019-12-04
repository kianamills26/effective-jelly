<h1 class="contract">userinsert</h1>
---
spec-version: 0.0.2
summary: This action will insert a profile. If an entry exists with the same name as the specified user parameter, the record is updated with the display name, about me string, location, image, language, and platform parameters. If a record does not exist, a new record is created. 

<h1 class="contract">create</h1>
---
spec-version: 0.0.2
summary: This action will create a new asset (non fungible token). If requireclaim = "false", then the newly created asset will be transferred to the owner (but author's RAM will be used until the asset is transferred again). If set to "true", the author will remain to be the owner, but an offer will be created for the account specified in the owner field to claim the asset using the owner's RAM. 

<h1 class="contract">claim</h1>
---
spec-version: 0.0.2
summary: This action claims the specified assets (assuming they were offered to claimer by the asset owner). 

<h1 class="contract">transfer</h1>
---
spec-version: 0.0.2
summary: This action will transfer one or more assets by changing scope. Sender's RAM will be charged to transfer asset. Transfer will fail if asset is offered for claim or is delegated.

<h1 class="contract">offer</h1>
---
spec-version: 0.0.2
summary: This is an alternative to the transfer action. Offer can be used by an asset owner to transfer the asset without using the their RAM. After an offer is made, the account specified in {{newowner}} is able to make a claim, and take control of the asset using their RAM. Offer action is not available if an asset is delegated (borrowed).

<h1 class="contract">delegate</h1>
---
spec-version: 0.0.2
summary: This action delegates asset to {{to}} account. This action changes the asset owner by calling the transfer action. It also adds a record in the delegates table to record the asset as borrowed.  This blocks the asset from all owner actions (transfers, offers, burning by borrower).

<h1 class="contract">undelegate</h1>
---
spec-version: 0.0.2
summary: This action undelegates assets from {{from}} account. Executing action by real owner will return asset immediately, and the entry in the delegates table recording the borrowing will be erased.