c1_tmpl_deduction * __thiscall tmpl_deduce_from_operands(c1_ovl_resolution *res,c1_symbol *sym)

{
  int iVar1;
  c1_type *pcVar2;
  c1_type *type2;
  c1_u8 *deduction;
  byte bVar3;
  char cVar4;
  ushort uVar5;
  uint uVar6;
  c1_tmpl_deduction *deduction_00;
  c1_u32 arg_count;
  uint *operand_type_slot;
  
  if ((sym->kind & 0x1f) == 8) {
    arg_count = res->nargs - 1;
  }
  else {
    arg_count = res->nargs;
  }
  uVar6 = type_function_arity_match
                    ((c1_type *)((uint)sym->type & -(uint)((sym->type->code & 0x80) != 0)),arg_count
                    );
  deduction = g_arenas[5].cur;
  if ((-1 < (int)uVar6) && ((int)uVar6 < 2)) {
    return (c1_tmpl_deduction *)0x0;
  }
  g_arenas[5].cur = g_arenas[5].cur + 0x30;
  iVar1 = *(int *)(*(int *)(((uint)sym->type & -(uint)((sym->type->code & 0x80) != 0)) + 8) + 0xc);
  operand_type_slot = (uint *)(iVar1 + 8);
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  if (deduction == (c1_u8 *)0x0) {
    deduction_00 = (c1_tmpl_deduction *)0x0;
  }
  else {
    deduction_00 = tmpl_deduction_begin
                             ((c1_tmpl_deduction *)deduction,sym,(c1_arg_list *)0x0,0,'\0');
  }
  if (((sym->flags1 & 4) == 0) || ((*(byte *)((int)&sym->tail + 8) & 1) == 0)) {
    pcVar2 = (c1_type *)*operand_type_slot;
    operand_type_slot = (uint *)(iVar1 + 0xc);
    uVar5 = tmpl_type_find_parameter(pcVar2,1,0);
    if (uVar5 != 0) {
      bVar3 = tmpl_deduce_from_argument_type(deduction_00,pcVar2,res->args);
      if (bVar3 == 0) {
        return (c1_tmpl_deduction *)0x0;
      }
      *deduction_00->param_bytes = '\x01';
    }
  }
  if ((res->extra).right != (c1_node *)0x0) {
    pcVar2 = (c1_type *)*operand_type_slot;
    uVar5 = tmpl_type_find_parameter(pcVar2,1,0);
    if (uVar5 != 0) {
      type2 = ((res->extra).right)->type;
      if ((type2->code == 0x80c) || (type2->code == 0x80e)) {
        if (type2->code == 0x80c) {
          deduction_00 = tmpl_deduce_from_overloaded_argument
                                   (deduction_00,((res->extra).right)->left,(c1_arg_list *)0x0,
                                    pcVar2,(c1_symbol **)0x0);
          if (deduction_00 != (c1_tmpl_deduction *)0x0) goto LAB_104a7521;
        }
        return (c1_tmpl_deduction *)0x0;
      }
      cVar4 = tmpl_unify_types(deduction_00,pcVar2,type2,'\x01');
      if (cVar4 == '\0') {
        return (c1_tmpl_deduction *)0x0;
      }
      deduction_00->param_bytes[1] = '\x01';
    }
  }
LAB_104a7521:
  cVar4 = tmpl_specialize_function(deduction_00);
  return (c1_tmpl_deduction *)(-(uint)(cVar4 != '\0') & (uint)deduction_00);
}

