uint32_t __fastcall evaluate_compare_from_available(c2_bitset *avail,c2_symbol *cmp_expr)

{
  uint16_t type;
  c2_cse_expr *pcVar1;
  c2_tuple *pcVar2;
  uint32_t uVar3;
  uint32_t *puVar4;
  int iVar5;
  
  uVar3 = bitset_test(avail,cmp_expr->id);
  if (uVar3 == 0) {
    pcVar1 = (cmp_expr->u18).expr;
    type = pcVar1->type;
    puVar4 = evaluate_compare_dispatch_a(pcVar1->op);
    pcVar2 = (c2_tuple *)*puVar4;
    while( true ) {
      if (pcVar2 == (c2_tuple *)0x0) {
        puVar4 = evaluate_compare_dispatch_b(pcVar1->op);
        pcVar2 = (c2_tuple *)*puVar4;
        while( true ) {
          if (pcVar2 == (c2_tuple *)0x0) {
            return 3;
          }
          puVar4 = puVar4 + 1;
          iVar5 = cse_available_value_of(pcVar2,type);
          if ((iVar5 != 0) && (uVar3 = bitset_test(avail,*(uint32_t *)(iVar5 + 0x1c)), uVar3 != 0))
          break;
          pcVar2 = (c2_tuple *)*puVar4;
        }
        return 2;
      }
      puVar4 = puVar4 + 1;
      iVar5 = cse_available_value_of(pcVar2,type);
      if ((iVar5 != 0) && (uVar3 = bitset_test(avail,*(uint32_t *)(iVar5 + 0x1c)), uVar3 != 0))
      break;
      pcVar2 = (c2_tuple *)*puVar4;
    }
  }
  return 1;
}

