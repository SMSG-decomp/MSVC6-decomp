c1_node * __cdecl expr_build_pseudo_destructor_call(char op,c1_node *node,int name)

{
  byte bVar1;
  ushort uVar2;
  c1_scope_stack *pcVar3;
  void *pvVar4;
  c1_symbol *pcVar5;
  c1_node *pcVar6;
  c1_symbol *pcVar7;
  c1_type *pcVar8;
  char *pcVar9;
  c1_type *pcVar10;
  short n;
  
  if (node == (c1_node *)0x0) {
LAB_1046d5f5:
    pcVar3 = g_current_scope;
    g_current_scope->reported = '\0';
    pcVar3->qual_class = (c1_symbol *)0x0;
    pcVar3->access_op = '\x01';
    pcVar3->qualified = '\0';
    pcVar6 = tree_new_zero_flagged();
    return pcVar6;
  }
  pcVar10 = node->type;
  uVar2 = pcVar10->code;
  if ((((uVar2 & 0x200) == 0) &&
      ((-1 < (char)uVar2 ||
       ((((uVar2 & 0x8f) != 0x86 && ((uVar2 & 0x8f) != 0x82)) ||
        (pcVar10 = pcVar10->base, (pcVar10->code >> 9 & 1) == 0)))))) ||
     (pcVar7 = (pcVar10->extra).cls, pcVar7 == (c1_symbol *)0x0)) {
    pcVar7 = expr_lookup_pseudo_destructor_name((fe_name *)name,(c1_symbol *)0x0);
    if (pcVar7 == (c1_symbol *)0x0) {
      if (op == 'S') {
        n = 0x12d;
      }
      else {
        n = 0x12e;
      }
      diag_error(n,name);
    }
    else if ((pcVar7->flags2 & 0x10) == 0) {
      pcVar9 = "->~";
      if (op != 'S') {
        pcVar9 = ".~";
      }
      diag_error(0x144,pcVar7->name,pcVar9);
    }
    else {
      pcVar10 = pcVar7->type;
      pcVar8 = type_get_base(node->type);
      if (pcVar10 != pcVar8) {
        pcVar9 = "->~";
        if (op != 'S') {
          pcVar9 = ".~";
        }
        diag_error(0x145,pcVar10,pcVar9);
      }
    }
    goto LAB_1046d5f5;
  }
  pvVar4 = (void *)0x0;
  if ((((pcVar7->detail).cls)->flags3e & 1) != 0) {
    pvVar4 = tmpl_template_of_instance(pcVar7);
  }
  if ((pcVar7->name == (fe_name *)name) ||
     ((pvVar4 != (void *)0x0 && (*(int *)((int)pvVar4 + 8) == name)))) {
    if ((pcVar7->flags1 & 0x20) != 0x20) goto LAB_1046d5be;
    bVar1 = ((pcVar7->detail).cls)->implicit_state41;
  }
  else {
    pcVar5 = expr_lookup_pseudo_destructor_name((fe_name *)name,pcVar7);
    if (((pcVar5 == (c1_symbol *)0x0) || ((pcVar5->type->code & 0x200) == 0)) ||
       ((pcVar5->type->extra).cls != pcVar7)) {
      diag_error(300,pcVar7,name);
      goto LAB_1046d5f5;
    }
    if ((pcVar7->flags1 & 0x20) != 0x20) goto LAB_1046d5be;
    bVar1 = ((pcVar7->detail).cls)->implicit_state41;
  }
  if ((bVar1 & 0x10) == 0) {
    g_compile_flags_c8 = g_compile_flags_c8 | 0x800000;
    pcVar6 = expr_build_destructor_call(pcVar7,node,4,0,0);
    return pcVar6;
  }
LAB_1046d5be:
  pcVar3 = g_current_scope;
  g_current_scope->reported = '\0';
  pcVar3->qual_class = (c1_symbol *)0x0;
  pcVar3->access_op = '\x01';
  pcVar3->qualified = '\0';
  pcVar6 = tree_new_zero_constant();
  return pcVar6;
}

