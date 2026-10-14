char * __thiscall idb_header_stream_name(void *idb,void *include_state,char *buf,uint size)

{
  char *pcVar1;
  
  pcVar1 = idb_header_file_name(include_state,*(void **)((int)idb + 0x184));
  pcVar1 = pdb_relative_path(pcVar1);
  _snprintf(buf,size,"/ipm/header/%s",pcVar1);
  buf[size - 1] = '\0';
  return buf;
}

