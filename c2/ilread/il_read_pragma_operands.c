void __fastcall il_read_pragma_operands(c2_reader_op *op)

{
  char cVar1;
  int16_t iVar2;
  ushort uVar3;
  short sVar4;
  char *codes;
  uint uVar5;
  int32_t iVar6;
  uint32_t *block;
  int iVar7;
  uint32_t size;
  c2_warning_state *pair;
  char buf [2080];
  
  codes = g_il_pragma_subop_table[(char)op->arg].codes;
  if (codes != (char *)0x0) {
    cVar1 = *codes;
    while (cVar1 != '\0') {
      switch(cVar1) {
      case '\x02':
        uVar3 = il_read_short();
        iVar7 = (uint)uVar3 + g_il_line_base;
        op->value = iVar7;
        op->value_hi = iVar7 >> 0x1f;
        break;
      default:
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2pragma.c",0xdb);
      case '\v':
        iVar7 = il_read_byte();
        il_read_object_comment((int)(char)iVar7);
        break;
      case '\f':
        sVar4 = il_read_counted_string(buf,0x81e);
        size = (int)sVar4 + 1;
        block = arena_alloc(2,size);
        op->value = (int32_t)block;
        buf[sVar4] = '\0';
        goto LAB_107304be;
      case '\r':
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2pragma.c",0x8e);
      case '\x0e':
        iVar2 = il_read_short();
        *(int16_t *)&op->value = iVar2;
        break;
      case '\x14':
        iVar6 = il_read_long();
        op->value = iVar6;
        op->value_hi = iVar6 >> 0x1f;
        break;
      case '\x15':
switchD_1073040e_caseD_15:
        iVar2 = il_read_short();
        op->value = (int)iVar2;
        op->value_hi = (int)iVar2 >> 0x1f;
        break;
      case '\x16':
        g_frontend_id_limit = il_read_id();
        g_next_fe_id = g_frontend_id_limit;
        break;
      case '\x17':
        pair = (c2_warning_state *)buf;
        size = 4;
        buf._0_2_ = il_read_short();
        iVar2 = buf._0_2_;
        while (iVar2 != -1) {
          iVar7 = il_read_byte();
          pair->state = (short)(char)iVar7;
          pair = pair + 1;
          size = size + 4;
          iVar2 = il_read_short();
          pair->warning = iVar2;
        }
        block = arena_alloc(1,size);
        op->sym = (c2_fe_symbol *)block;
LAB_107304be:
        pair = (c2_warning_state *)buf;
        for (uVar5 = size >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *block = (uint32_t)*pair;
          pair = pair + 1;
          block = (uint32_t *)(block + 1);
        }
        for (uVar5 = size & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(char *)&((c2_warning_state *)block)->warning = (char)pair->warning;
          pair = (c2_warning_state *)((int)&pair->warning + 1);
          block = (uint32_t *)((int)&((c2_warning_state *)block)->warning + 1);
        }
        break;
      case '\x18':
        uVar5 = il_read_id();
        op->value = uVar5;
        break;
      case 'l':
        if (g_pdb_il_mode == 0) goto switchD_1073040e_caseD_15;
        g_il_line_base = il_read_long();
        iVar7 = g_il_line_base >> 0x1f;
        op->value = g_il_line_base;
        op->value_hi = iVar7;
        break;
      case 's':
        uVar5 = il_read_id();
        g_cur_source_file = source_file_name_lookup(uVar5);
        op->sym = (c2_fe_symbol *)g_cur_source_file;
        op->op = 0x56;
      }
      codes = codes + 1;
      cVar1 = *codes;
    }
  }
  return;
}

