void __fastcall label_delete(c2_tuple *node)

{
  c2_fe_symbol *label;
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  
  label = (c2_fe_symbol *)node->src;
  if ((*(byte *)&label->u3e & 1) != 0) {
    if (label->role != 'S') {
      if (label->role != 'V') {
        pcVar1 = node->prev;
        label->section_id = g_cur_func_sym->section_id;
        pcVar2 = node->next;
        pcVar1->next = pcVar2;
        pcVar2->prev = pcVar1;
        node_free((c2_node *)node);
        return;
      }
      cxx_eh_label_deleted(label);
      pcVar1 = node->prev;
      pcVar2 = node->next;
      pcVar1->next = pcVar2;
      pcVar2->prev = pcVar1;
      node_free((c2_node *)node);
      return;
    }
    seh_scopes_forget_label(g_cur_function,label);
  }
  pcVar1 = node->prev;
  pcVar2 = node->next;
  pcVar1->next = pcVar2;
  pcVar2->prev = pcVar1;
  node_free((c2_node *)node);
  return;
}

