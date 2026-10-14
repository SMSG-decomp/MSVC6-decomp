c1_u8 * __thiscall expr_build_member_access_implicit(c1_scope_stack *scope,void *name)

{
  c1_lookup_entry *pcVar1;
  byte saved_flag;
  
  saved_flag = scope->reported;
  scope->reported = '\x01';
  pcVar1 = lookup_name_in_context(scope,name,0x132);
  scope->reported = saved_flag;
  return (c1_u8 *)pcVar1;
}

