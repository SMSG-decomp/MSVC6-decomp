c2_iv_derived_choice * __fastcall
collect_iv_rewrite_chain
          (c2_symbol *biv,c2_operand *limit,c2_loop *loop,uint16_t cmp_type,int check_limit_fit,
          int check_init_fit)

{
  c2_iv_derived_choice *pcVar1;
  c2_iv_derived_choice *pcVar2;
  c2_iv_derived_choice *pcVar3;
  undefined2 in_stack_0000000a;
  c2_operand *local_4;
  
  local_4 = limit;
  pcVar1 = (c2_iv_derived_choice *)
           ltr_choose_derived_iv(loop,biv,&local_4,_cmp_type,check_limit_fit,check_init_fit);
  pcVar3 = pcVar1;
  if (pcVar1 == (c2_iv_derived_choice *)0x0) {
    return (c2_iv_derived_choice *)0x0;
  }
  while (pcVar2 = (c2_iv_derived_choice *)
                  ltr_choose_derived_iv
                            (loop,pcVar3->iv,&local_4,_cmp_type,check_limit_fit,check_init_fit),
        pcVar2 != (c2_iv_derived_choice *)0x0) {
    pcVar3->next = pcVar2;
    pcVar3 = pcVar2;
  }
  return pcVar1;
}

