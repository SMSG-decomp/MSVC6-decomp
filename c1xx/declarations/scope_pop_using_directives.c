void __fastcall scope_pop_using_directives(c1xx_scope *scope)

{
  c1_using_directive *pcVar1;
  
  pcVar1 = scope->usings;
  do {
    using_list_deactivate(pcVar1->visible_in,(int)pcVar1->ns);
    pcVar1 = pcVar1->next;
  } while (pcVar1 != (c1_using_directive *)0x0);
  return;
}

