int __fastcall pdb_stream_replace(uint8_t *buf,int size)

{
  int iVar1;
  
  iVar1 = StreamReplace(g_incr_info_stream,buf,size);
  return iVar1;
}

