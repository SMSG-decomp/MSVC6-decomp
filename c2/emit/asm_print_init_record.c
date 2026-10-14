int __fastcall asm_print_init_record(c2_init *rec)

{
  c2_fe_symbol *s;
  uint8_t *puVar1;
  int iVar2;
  c2_init *pcVar3;
  uint n;
  int iVar4;
  c2_init *size;
  char *pcVar5;
  
  switch(rec->kind) {
  case 1:
    iVar2 = (rec->u18).repeat;
    n = (uint)(rec->u08).data.size;
    iVar4 = iVar2 * n;
    if ((rec->u08).data.value_kind != 6) {
      asm_print_data_scalar(rec);
      return iVar4;
    }
    if (0 < iVar2) {
      if (iVar2 == 0) {
        return iVar4;
      }
      puVar1 = (uint8_t *)(rec->u08).header.offset;
      while( true ) {
        iVar2 = iVar2 + -1;
        asm_print_db_bytes(puVar1,n);
        if (iVar2 == 0) break;
        g_asm_column = 0;
        asm_printf(g_asm_newline);
        asm_pad_to_column(8);
      }
      return iVar4;
    }
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\list.c",0x511);
  case 2:
    size = (c2_init *)(int)(char)(rec->u08).address.size;
    asm_pad_to_column(8);
    pcVar5 = asm_data_directive_for_size((int)size);
    iVar2 = asm_printf("%s",pcVar5);
    g_asm_column = g_asm_column + iVar2;
    asm_pad_to_column(0x10);
    s = fe_symbol_lookup_id((rec->u08).address.target_id);
    if (((s->cls == '\x04') || (s->cls == '\x01')) && ((s->storage & 0x1000) != 0)) {
      s = (c2_fe_symbol *)fe_symbol_resolve_redirect((int)s);
    }
    pcVar5 = "FLAT:";
    if (g_opt_dos == 0) {
      pcVar5 = "";
    }
    puVar1 = fe_symbol_external_name(s);
    iVar2 = asm_printf("%s%s",pcVar5,puVar1);
    pcVar3 = (c2_init *)(rec->u08).header.offset;
    g_asm_column = g_asm_column + iVar2;
    if (pcVar3 == (c2_init *)0x0) {
      return (int)size;
    }
    pcVar5 = "%+ld";
    break;
  default:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\list.c",0x537);
  case 4:
    iVar2 = (int)(char)(rec->u08).align;
    size = (c2_init *)(iVar2 - g_asm_current_segment->refcount & iVar2 - 1U);
    asm_pad_to_column(8);
    pcVar3 = (c2_init *)asm_align_keyword(iVar2);
    pcVar5 = "ALIGN\t%d";
    break;
  case 8:
    size = (rec->u08).header.list_next;
    pcVar5 = "\tORG $%+ld";
    pcVar3 = size;
  }
  iVar2 = asm_printf(pcVar5,pcVar3);
  g_asm_column = g_asm_column + iVar2;
  return (int)size;
}

