void __fastcall assign_nested_function_temp_homes(c2_function *fn)

{
  c2_tuple *pcVar1;
  c2_function *fn_00;
  
  for (pcVar1 = fn->cfg->first->head; pcVar1 != (c2_tuple *)0x0; pcVar1 = pcVar1->next) {
    if ((pcVar1->op == 0x1a0) &&
       (fn_00 = ((pcVar1->u20).eh_construct)->object->funclet, fn_00 != (c2_function *)0x0)) {
      assign_temp_homes_in_reference_order(fn_00);
    }
  }
  return;
}

