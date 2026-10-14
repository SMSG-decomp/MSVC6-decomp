c1_u8 * __thiscall lookup_name_mask_121(c1_scope_stack *ctx,fe_name *name)

{
  c1_lookup_entry *pcVar1;
  
  pcVar1 = lookup_name_in_context(ctx,name,0x121);
  return (c1_u8 *)pcVar1;
}

