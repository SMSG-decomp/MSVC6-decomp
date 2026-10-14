c2_cse_expr * __fastcall cse_insert(uint32_t bucket,uint32_t op,uint16_t type)

{
  c2_cse_expr *pcVar1;
  c2_cse_expr *pcVar2;
  c2_symbol *pcVar3;
  c2_operand *pcVar4;
  uint16_t type_00;
  
  pcVar2 = arena_alloc(0xe,0x14);
  type_00 = type;
  if (op == 0x17d) {
    type_00 = 0x8000;
  }
  pcVar3 = cse_new_expression_symbol(type_00);
  pcVar2->sym = pcVar3;
  pcVar2->op = op;
  (pcVar3->u18).expr = pcVar2;
  pcVar2->type = type;
  pcVar4 = cse_claim_key_operands();
  pcVar1 = g_expr_hash[bucket];
  pcVar2->operands = pcVar4;
  pcVar2->next = pcVar1;
  g_expr_count = g_expr_count + 1;
  g_expr_hash[bucket] = pcVar2;
  if (op == 0x14c) {
    g_address_expr_count = g_address_expr_count + 1;
    pcVar3->order_next = g_address_expr_list;
    g_address_expr_list = pcVar3;
  }
  return pcVar2;
}

