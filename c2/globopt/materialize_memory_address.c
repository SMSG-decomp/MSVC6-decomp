c2_operand * __fastcall materialize_memory_address(c2_tuple *anchor,c2_operand *mem)

{
  c2_tuple *addr_tuple;
  c2_operand *pcVar1;
  c2_operand *b;
  uint32_t uVar2;
  c2_const_operand *pcVar3;
  c2_tuple *pcVar4;
  c2_tuple *scaled;
  uint16_t type;
  code *insert_fn_00;
  c2_operand *local_8;
  c2_symbol *local_4;
  c2_insert_fn *insert_fn;
  
  uVar2 = mem->op;
  if (uVar2 == 0x14c) {
    pcVar1 = mem->base;
    local_4 = pcVar1->sym;
    type = pcVar1->type;
    local_8 = materialize_symbol_address(anchor,mem,type);
    if (local_8 == (c2_operand *)0x0) goto LAB_10763d33;
LAB_10763d1b:
    addr_tuple = tuple_new_cse_binary(0x16d,type,pcVar1,local_8,tuple_insert_before,anchor);
  }
  else {
    if (uVar2 == 0x14d) {
      pcVar1 = mem->index;
      local_8 = mem->base;
      local_4 = pcVar1->sym;
      type = pcVar1->type;
      b = materialize_symbol_address(anchor,mem,type);
      if (b != (c2_operand *)0x0) {
        pcVar4 = tuple_new_cse_binary(0x16d,type,local_8,b,tuple_insert_before,anchor);
        local_8 = pcVar4->dst;
      }
      if ((mem->flags & 0xf) != 0) {
        uVar2 = 1 << (mem->flags & 0xf);
        insert_fn = tuple_insert_before;
        pcVar4 = anchor;
        pcVar3 = operand_new_intconst(type,uVar2,(int)uVar2 >> 0x1f);
        pcVar4 = tuple_new_cse_binary(0x16f,type,pcVar1,pcVar3,insert_fn,pcVar4);
        pcVar1 = pcVar4->dst;
      }
      goto LAB_10763d1b;
    }
    if (uVar2 != 0x14f) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\globlopt.c",0x1eb3);
    }
    pcVar1 = mem->index;
    type = pcVar1->type;
    local_4 = pcVar1->sym;
    local_8 = materialize_symbol_address(anchor,mem,type);
    addr_tuple = (c2_tuple *)local_4;
    if ((mem->flags & 0xf) != 0) {
      uVar2 = 1 << (mem->flags & 0xf);
      insert_fn_00 = tuple_insert_before;
      pcVar4 = anchor;
      pcVar3 = operand_new_intconst(type,uVar2,(int)uVar2 >> 0x1f);
      scaled = tuple_new_cse_binary(0x16f,type,pcVar1,pcVar3,insert_fn_00,pcVar4);
      pcVar1 = scaled->dst;
      addr_tuple = scaled;
    }
    if (local_8 != (c2_operand *)0x0) goto LAB_10763d1b;
  }
  pcVar1 = (c2_operand *)((c2_symbol *)addr_tuple)->id;
  add_symbol_loop_use(local_4,addr_tuple);
LAB_10763d33:
  pcVar1 = (c2_operand *)node_clone((c2_node *)pcVar1);
  return pcVar1;
}

