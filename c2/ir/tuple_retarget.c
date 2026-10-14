void __fastcall tuple_retarget(c2_tuple *referrer,c2_node *label,int retarget_cases)

{
  c2_operand *old;
  
  if (referrer->kind == '\x11') {
    old = referrer->src;
    if (old->kind == '\x04') {
      label_remove_ref(*(c2_tuple **)((int)&old->sym->u30 + 2),(c2_node *)referrer);
    }
    if (label->kind == '\x1a') {
      label_add_ref((c2_tuple *)label,(c2_node *)referrer);
      label = (c2_node *)operand_new_labelref((c2_tuple *)label,0);
    }
    tuple_replace_src(referrer,old,(c2_operand *)label);
    return;
  }
  switch_retarget(referrer,label,retarget_cases);
  return;
}

