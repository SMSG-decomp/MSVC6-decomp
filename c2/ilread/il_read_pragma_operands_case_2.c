void il_read_pragma_operands_case_2(c2_reader_op *op,char *codes,int16_t scratch)

{
  int16_t iVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  int32_t iVar5;
  uint32_t *block;
  int iVar6;
  uint32_t size;
  c2_warning_state *pair;
  
code_r0x1077e153:
  uVar2 = il_read_short();
  iVar6 = (uint)uVar2 + g_il_line_base;
  op->value = iVar6;
  op->value_hi = iVar6 >> 0x1f;
LAB_10730431:
  codes = codes + 1;
  if (*codes == '\0') {
    return;
  }
  switch(*codes) {
  case '\x02':
    goto code_r0x1077e153;
  default:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2pragma.c",0xdb);
  case '\v':
    iVar6 = il_read_byte();
    il_read_object_comment((int)(char)iVar6);
    goto LAB_10730431;
  case '\f':
    sVar3 = il_read_counted_string((char *)&scratch,0x81e);
    size = (int)sVar3 + 1;
    block = arena_alloc(2,size);
    op->value = (int32_t)block;
    *(undefined1 *)((int)&scratch + (int)sVar3) = 0;
    break;
  case '\r':
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2pragma.c",0x8e);
  case '\x0e':
    iVar1 = il_read_short();
    *(int16_t *)&op->value = iVar1;
    goto LAB_10730431;
  case '\x14':
    iVar5 = il_read_long();
    op->value = iVar5;
    op->value_hi = iVar5 >> 0x1f;
    goto LAB_10730431;
  case '\x15':
    goto switchD_1073040e_caseD_15;
  case '\x16':
    g_frontend_id_limit = il_read_id();
    g_next_fe_id = g_frontend_id_limit;
    goto LAB_10730431;
  case '\x17':
    pair = (c2_warning_state *)&scratch;
    size = 4;
    scratch = il_read_short();
    iVar1 = scratch;
    while (iVar1 != -1) {
      iVar6 = il_read_byte();
      pair->state = (short)(char)iVar6;
      pair = pair + 1;
      size = size + 4;
      iVar1 = il_read_short();
      pair->warning = iVar1;
    }
    block = arena_alloc(1,size);
    op->sym = (c2_fe_symbol *)block;
    break;
  case '\x18':
    uVar4 = il_read_id();
    op->value = uVar4;
    goto LAB_10730431;
  case 'l':
    if (g_pdb_il_mode == 0) {
switchD_1073040e_caseD_15:
      iVar1 = il_read_short();
      op->value = (int)iVar1;
      op->value_hi = (int)iVar1 >> 0x1f;
    }
    else {
      g_il_line_base = il_read_long();
      iVar6 = g_il_line_base >> 0x1f;
      op->value = g_il_line_base;
      op->value_hi = iVar6;
    }
    goto LAB_10730431;
  case 's':
    goto switchD_1073040e_caseD_73;
  }
  pair = (c2_warning_state *)&scratch;
  for (uVar4 = size >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *block = (uint32_t)*pair;
    pair = pair + 1;
    block = (uint32_t *)(block + 1);
  }
  for (uVar4 = size & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(char *)&((c2_warning_state *)block)->warning = (char)pair->warning;
    pair = (c2_warning_state *)((int)&pair->warning + 1);
    block = (uint32_t *)((int)&((c2_warning_state *)block)->warning + 1);
  }
  goto LAB_10730431;
switchD_1073040e_caseD_73:
  uVar4 = il_read_id();
  g_cur_source_file = source_file_name_lookup(uVar4);
  op->sym = (c2_fe_symbol *)g_cur_source_file;
  op->op = 0x56;
  goto LAB_10730431;
}

