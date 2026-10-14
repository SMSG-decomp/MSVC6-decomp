c2_symbol * __cdecl get_expression_symbol_n(uint32_t op,uint16_t type,uint32_t count,...)

{
  uint32_t *puVar1;
  uint32_t bucket;
  c2_cse_expr *pcVar2;
  uint uVar3;
  c2_operand **ppcVar4;
  uint32_t *puVar5;
  
  if (9 < count) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\hash.c",0x2dd);
  }
  uVar3 = 0;
  if (count != 0) {
    puVar5 = &count;
    ppcVar4 = g_expr_operand_scratch;
    do {
      puVar1 = puVar5 + 1;
      puVar5 = puVar5 + 1;
      if ((c2_operand *)*puVar1 == (c2_operand *)0x0) break;
      *ppcVar4 = (c2_operand *)*puVar1;
      uVar3 = uVar3 + 1;
      ppcVar4 = ppcVar4 + 1;
    } while (uVar3 < count);
  }
  g_expr_operand_scratch[uVar3] = (c2_operand *)0x0;
  bucket = hash_expression(op,type);
  pcVar2 = cse_lookup(bucket,op,type);
  if (pcVar2 == (c2_cse_expr *)0x0) {
    pcVar2 = cse_insert(bucket,op,type);
  }
  return pcVar2->sym;
}

