int __fastcall remat_cheaper_than_spill(c2_live_range *lr,c2_tuple *def,c2_tuple *end)

{
  c2_operand *op;
  int iVar1;
  int iVar2;
  c2_operand *use_addr;
  int iVar3;
  c2_tuple *t;
  c2_operand *local_4;
  
  iVar3 = 0;
  iVar1 = 0;
  t = def;
  do {
    t = t->next;
    if ((t->flags & 1) != 0) {
      iVar1 = iVar1 + 1;
      if (10 < iVar1) {
        return 1;
      }
      for (op = t->src; op != (c2_operand *)0x0; op = op->next) {
        if (((op->kind == '\x01') && ((op->u18).reg == (c2_symbol *)lr)) &&
           (iVar2 = operand_list_has_same_reg(op), iVar2 == 0)) {
          use_addr = find_mem_operand_using(t,op,&local_4);
          iVar2 = remat_use_cost(use_addr,def);
          iVar3 = iVar3 + iVar2;
        }
      }
    }
  } while (t != end);
  iVar1 = remat_definition_cost(def);
  return (uint)(iVar3 <= iVar1);
}

