void __fastcall label_redirect_and_delete(c2_tuple *t,c2_tuple *label)

{
  uint32_t uVar1;
  
  label_retarget_all_refs(t,(c2_node *)label);
  uVar1 = label_is_removable(t);
  if (uVar1 == 0) {
    label_delete(t);
  }
  return;
}

