void __fastcall emit_gz_stack_fill(c2_function *fn,c2_tuple *anchor,int size,int offset)

{
  uint uVar1;
  c2_operand *pcVar2;
  c2_const_operand *pcVar3;
  c2_tuple *pcVar4;
  c2_operand *dst;
  int iVar5;
  bool bVar6;
  code *pcVar7;
  c2_operand *pcVar8;
  c2_insert_fn *insert_fn;
  
  if (size < 1) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\MDmisc.c",0x4dc);
  }
  uVar1 = size & 0x80000003;
  bVar6 = uVar1 == 0;
  if ((int)uVar1 < 0) {
    bVar6 = (uVar1 - 1 | 0xfffffffc) == 0xffffffff;
  }
  if (!bVar6) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\MDmisc.c",0x4dd);
  }
  if (size < 0x10) {
    iVar5 = 0;
    if (0 < size) {
      do {
        pcVar8 = (c2_operand *)0x0;
        pcVar2 = operand_new_hardreg(6,0x1004);
        pcVar2 = operand_new_addr(0x14c,0x1004,(c2_symbol *)0x0,iVar5 + offset,pcVar2,pcVar8);
        insert_fn = tuple_insert_after;
        pcVar3 = operand_new_intconst(0x1004,g_opt_stack_fill,0);
        anchor = tuple_new(1,0x1004,pcVar2,pcVar3,insert_fn,anchor);
        iVar5 = iVar5 + 4;
      } while (iVar5 < size);
      return;
    }
  }
  else if (size < 0x28) {
    g_reg_symbols[1].flags5 = g_reg_symbols[1].flags5 | 0x10;
    insert_fn = tuple_insert_after;
    pcVar3 = operand_new_intconst(0x1004,g_opt_stack_fill,0);
    pcVar2 = operand_new_hardreg(1,0x1004);
    pcVar4 = tuple_new(1,0x1004,pcVar2,pcVar3,insert_fn,anchor);
    iVar5 = 0;
    if (0 < size) {
      do {
        pcVar8 = (c2_operand *)0x0;
        pcVar2 = operand_new_hardreg(6,0x1004);
        pcVar2 = operand_new_addr(0x14c,0x1004,(c2_symbol *)0x0,iVar5 + offset,pcVar2,pcVar8);
        insert_fn = tuple_insert_after;
        pcVar8 = operand_new_hardreg(1,0x1004);
        pcVar4 = tuple_new(1,0x1004,pcVar2,pcVar8,insert_fn,pcVar4);
        iVar5 = iVar5 + 4;
      } while (iVar5 < size);
      return;
    }
  }
  else {
    g_reg_symbols[2].flags5 = g_reg_symbols[2].flags5 | 0x10;
    g_reg_symbols[1].flags5 = g_reg_symbols[1].flags5 | 0x10;
    g_reg_symbols[8].flags5 = g_reg_symbols[8].flags5 | 0x10;
    uVar1 = fn->fsym->attrs & 0x1c;
    if ((uVar1 == 4) || (uVar1 == 0x14)) {
      anchor = insert_push_reg(2,anchor);
    }
    pcVar8 = (c2_operand *)0x0;
    pcVar2 = operand_new_hardreg(6,0x1004);
    pcVar2 = operand_new_addr(0x14c,0x1004,(c2_symbol *)0x0,offset,pcVar2,pcVar8);
    insert_fn = tuple_insert_after;
    pcVar8 = operand_new_hardreg(8,0x1004);
    pcVar4 = tuple_new(0x12,0x1004,pcVar8,pcVar2,insert_fn,anchor);
    pcVar7 = tuple_insert_after;
    iVar5 = size + (size >> 0x1f & 3U);
    pcVar3 = operand_new_intconst(0x1004,iVar5 >> 2,iVar5 >> 0x1f);
    pcVar2 = operand_new_hardreg(2,0x1004);
    pcVar4 = tuple_new(1,0x1004,pcVar2,pcVar3,pcVar7,pcVar4);
    pcVar7 = tuple_insert_after;
    pcVar3 = operand_new_intconst(0x1004,g_opt_stack_fill,0);
    pcVar2 = operand_new_hardreg(1,0x1004);
    pcVar4 = tuple_new(1,0x1004,pcVar2,pcVar3,pcVar7,pcVar4);
    pcVar7 = tuple_insert_after;
    pcVar2 = operand_new_hardreg(8,0x1004);
    pcVar8 = operand_new_hardreg(1,0x1004);
    dst = operand_new_hardreg(8,0x1004);
    pcVar4 = tuple_new_binary(0x111,0x1004,dst,pcVar8,pcVar2,pcVar7,pcVar4);
    pcVar2 = operand_new_hardreg(2,0x1004);
    tuple_append_src(pcVar4,pcVar2);
    pcVar2 = operand_new_hardreg(2,0x1004);
    tuple_append_dst(pcVar4,pcVar2);
    if ((uVar1 == 4) || (uVar1 == 0x14)) {
      insert_pop_reg(2,pcVar4);
    }
  }
  return;
}

