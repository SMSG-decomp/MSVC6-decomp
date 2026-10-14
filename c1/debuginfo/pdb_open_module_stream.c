int __thiscall pdb_open_module_stream(c1_idb_state *idb,char *source_name,char *object_name)

{
  Stream *this;
  char *pcVar1;
  int iVar2;
  long lVar3;
  Stream *this_00;
  int iStack_114;
  char stream_name [270];
  
  pcVar1 = pdb_relative_path(object_name);
  _snprintf(stream_name,0x10e,"/ipm/mod/%s",pcVar1);
  stream_name[0x10d] = '\0';
  iVar2 = (*idb->pdb->vtbl->OpenStream)(idb->pdb,"/ipm",&idb->deps_stream);
  if (iVar2 != 0) {
    iVar2 = (*idb->pdb->vtbl->OpenStream)(idb->pdb,stream_name,&idb->regions_stream);
    if ((iVar2 != 0) &&
       (((idb->second_pdb == 0 && (idb->read_second_pdb == 0)) ||
        ((iVar2 = (*idb->pdb_2->vtbl->OpenStream)(idb->pdb_2,"/ipm",&idb->deps_stream_2), iVar2 != 0
         && (iVar2 = (*idb->pdb_2->vtbl->OpenStream)(idb->pdb_2,stream_name,&idb->regions_stream_2),
            iVar2 != 0)))))) {
      if (idb->read_second_pdb == 0) {
        this = idb->deps_stream;
        this_00 = idb->regions_stream;
      }
      else {
        this = idb->deps_stream_2;
        this_00 = idb->regions_stream_2;
      }
      lVar3 = (*this->vtbl->QueryCb)(this);
      if ((lVar3 == 0) ||
         ((iVar2 = idb_read_dependencies(idb,this,&iStack_114), iVar2 != 0 &&
          (((iStack_114 == 0 || (lVar3 = (*this_00->vtbl->QueryCb)(this_00), lVar3 == 0)) ||
           (iVar2 = idb_read_regions(idb,this_00), iVar2 != 0)))))) {
        iVar2 = idb_check_file_times(idb);
        return (uint)(iVar2 != 0);
      }
    }
  }
  return 0;
}

