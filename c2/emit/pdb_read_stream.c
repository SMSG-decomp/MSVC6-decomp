void * __fastcall pdb_read_stream(char *name,size_t *size)

{
  int iVar1;
  size_t _Size;
  void *pvVar2;
  c2_pdb_stream *stream;
  size_t read_size;
  
  iVar1 = PDBOpenStream(g_pdb,name,&stream);
  if (iVar1 == 0) {
    fatal_error(300,g_pdb_name);
  }
  _Size = StreamQueryCb(stream);
  pvVar2 = malloc(_Size);
  read_size = _Size;
  iVar1 = StreamRead(stream,0,pvVar2,&read_size);
  if (iVar1 == 0) {
    fatal_error(300,g_pdb_name);
  }
  StreamRelease(stream);
  *size = _Size;
  return pvVar2;
}

