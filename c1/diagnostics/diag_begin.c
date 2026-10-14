void __thiscall diag_begin(fe_diag_context *list,int position)

{
  int iVar1;
  
  iVar1 = list->nesting + 1;
  list->nesting = iVar1;
  if (iVar1 == 1) {
    list->state = 1;
    if (position == 0) {
      position = g_token_position;
    }
    list->position = position;
    list->indent = 0;
  }
  return;
}

