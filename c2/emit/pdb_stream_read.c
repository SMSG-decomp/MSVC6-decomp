int __fastcall pdb_stream_read(void *buf,int size)

{
  int iVar1;
  int local_4;
  
  local_4 = size;
  iVar1 = StreamRead(g_incr_info_stream,0,buf,&local_4);
  if (iVar1 == 0) {
    fatal_error(300,g_pdb_name);
  }
  return local_4;
}

