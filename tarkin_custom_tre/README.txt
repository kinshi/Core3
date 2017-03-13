Direction for re-packing after making edits to the IFF datatables


1. Remove this README file- seriously, do this...else the server will toss up errors on start trying to read THIS file from the TRE you created)
2. Using SIE (Synter's IFF Editor)Select TOC/Tree Builder, then Create .tre from directory on disk
3. Navigate to this folder, select 'tre' then 'OK'
4. Name, snd delect the destination folder for the TRE to be created in.

NOTE: The resulting TRE will have to be installed both in the client, and on the server for the changes to take full effect.

Do not forget to edit the swgemu_live.cfg file on the client, and config.lua on the server if you change the name of the file.

These files WILL change over time as more custom content is created.