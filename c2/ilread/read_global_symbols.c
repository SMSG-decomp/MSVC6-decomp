void __fastcall read_global_symbols(FILE *stream)

{
  FILE *pFVar1;
  uint uVar2;
  c2_init *pcVar3;
  int32_t iVar4;
  int iVar5;
  char *_Memory;
  size_t local_24;
  FILE local_20;
  
  g_il_stream = stream;
  do {
    iVar5 = il_read_byte();
    iVar5 = (int)(char)iVar5;
    switch(iVar5) {
    case 0:
      pcVar3 = alloc_init_record(iVar5);
      uVar2 = il_read_id();
      (pcVar3->u08).header.sym_id = uVar2;
      iVar4 = il_read_long();
      (pcVar3->u08).header.offset = iVar4;
      il_read_init_data(pcVar3);
      init_record_insert_sorted(pcVar3);
      break;
    default:
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2symtab.c",0x962);
    case 9:
      il_read_id();
      break;
    case 10:
      pcVar3 = alloc_init_record(iVar5);
      (pcVar3->u08).header.sym_id = 0;
      iVar4 = il_read_long();
      (pcVar3->u08).header.offset = iVar4;
      il_read_init_data(pcVar3);
      init_record_assign_offsets(pcVar3);
      init_records_free(pcVar3);
      break;
    case 0xc:
      il_read_byte();
      break;
    case 0xe:
      il_read_string(g_il_name_buffer,0x81e);
      _Memory = pdb_read_stream(g_il_name_buffer,&local_24);
      pFVar1 = g_il_stream;
      if (_Memory == (char *)0x0) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2symtab.c",0x952);
      }
      local_20._cnt = local_24;
      local_20._flag = 1;
      local_20._file = -1;
      local_20._ptr = _Memory;
      read_global_symbols(&local_20);
      free(_Memory);
      g_il_stream = pFVar1;
      break;
    case -1:
    case 0xf:
      return;
    }
  } while( true );
}

