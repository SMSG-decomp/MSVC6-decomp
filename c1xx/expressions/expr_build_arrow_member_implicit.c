c1_u8 * __thiscall expr_build_arrow_member_implicit(c1_scope_stack *scope,fe_name *name)

{
  c1_u8 *pcVar1;
  c1_u8 saved_reported;
  
  saved_reported = scope->reported;
  scope->reported = '\x01';
  pcVar1 = lookup_name_mask_121(scope,name);
  scope->reported = saved_reported;
  return pcVar1;
}

