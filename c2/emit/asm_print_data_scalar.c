void __fastcall asm_print_data_scalar(c2_init *rec)

{
  uint16_t uVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  uint size;
  
  iVar4 = (rec->u18).repeat;
  if ((rec->u08).data.value_kind == 5) {
    uVar1 = (rec->u08).data.size;
    if (uVar1 == 4) {
      asm_print_float_data(0x1004,(uint8_t *)&(rec->u08).header.offset,iVar4);
      return;
    }
    if (uVar1 == 8) {
      asm_print_float_data(0x1008,(uint8_t *)&(rec->u08).header.offset,iVar4);
      return;
    }
    if (uVar1 != 10) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\list.c",0x4da);
    }
    asm_print_float_data(0x100a,(uint8_t *)&(rec->u08).header.offset,iVar4);
  }
  else {
    asm_pad_to_column(8);
    size = (uint)(rec->u08).data.size;
    pcVar2 = asm_data_directive_for_size(size);
    iVar3 = asm_printf("%s",pcVar2);
    g_asm_column = g_asm_column + iVar3;
    asm_pad_to_column(0x10);
    if (1 < iVar4) {
      iVar3 = asm_printf("%ld DUP(",iVar4);
      g_asm_column = g_asm_column + iVar3;
    }
    switch(size) {
    case 1:
      iVar3 = asm_printf("0%01xH",(uint)*(byte *)((int)&rec->u08 + 4));
      break;
    case 2:
      iVar3 = asm_printf("0%xH",(uint)*(ushort *)((int)&rec->u08 + 4));
      break;
    default:
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\list.c",0x4f2);
    case 4:
      iVar3 = asm_printf("0%lxH",(rec->u08).header.offset);
      break;
    case 8:
      iVar3 = asm_printf("%08lx%08lxH",(rec->u08).header.sym_id,(rec->u08).header.offset);
    }
    g_asm_column = g_asm_column + iVar3;
    if (1 < iVar4) {
      iVar4 = asm_printf(")");
      g_asm_column = g_asm_column + iVar4;
      return;
    }
  }
  return;
}

