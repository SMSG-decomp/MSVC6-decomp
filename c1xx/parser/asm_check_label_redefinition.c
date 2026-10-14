void __cdecl asm_check_label_redefinition(int name)

{
  bool bVar1;
  int iVar2;
  c1_symbol *pcVar3;
  c1_node *pcVar4;
  
  bVar1 = false;
  pcVar3 = g_function_labels;
  if (g_function_labels != (c1_symbol *)0x0) {
    do {
      if (((pcVar3->detail).cls == (c1_class_record *)0x0) &&
         (iVar2 = str_compare_nocase(*(char **)(name + 4),pcVar3->name->text), iVar2 == 0)) {
        bVar1 = true;
        pcVar3->flags5 = pcVar3->flags5 | 0x10;
        if ((pcVar3->flags2 & 4) == 0) {
          pcVar4 = tree_new_node_typed('\x06',pcVar3,(c1_type *)0x0);
          label_emit_definition(pcVar4);
        }
        else {
          diag_error(0x19c,pcVar3);
        }
      }
    } while ((pcVar3->next != (c1_symbol *)0x0) &&
            (pcVar3 = (c1_symbol *)((int)&pcVar3->next[-1].tail + 4), pcVar3 != (c1_symbol *)0x0));
    if (bVar1) {
      return;
    }
  }
  pcVar3 = (c1_symbol *)label_new_user(name);
  pcVar3->flags5 = pcVar3->flags5 | 0x10;
  label_register(pcVar3);
  pcVar4 = tree_new_node_typed('\x06',pcVar3,(c1_type *)0x0);
  label_emit_definition(pcVar4);
  return;
}

