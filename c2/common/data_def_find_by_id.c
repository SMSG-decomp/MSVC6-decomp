c2_init * __fastcall data_def_find_by_id(uint32_t id)

{
  c2_init *pcVar1;
  
  pcVar1 = g_init_record_list;
  while( true ) {
    if (pcVar1 == (c2_init *)0x0) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2symtab.c",0xa4d);
    }
    if ((pcVar1->u08).header.sym_id == id) break;
    pcVar1 = (pcVar1->u08).header.list_next;
  }
  return pcVar1;
}

