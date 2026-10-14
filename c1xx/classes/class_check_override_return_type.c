char __cdecl
class_check_override_return_type(c1_sym_link *fn,c1_sym_link *base_fn,c1_symbol *cls,char report)

{
  c1_type *pcVar1;
  c1_type *pcVar2;
  c1_type *fn_type;
  c1_type *base_fn_type;
  
  fn_type = (fn->type).type;
  base_fn_type = (base_fn->type).type;
  if (((fn_type->extra).params)->list != ((base_fn_type->extra).params)->list) {
    return '\0';
  }
  if (((((base_fn_type->extra).params)->this_type->base->flags ^
       ((fn_type->extra).params)->this_type->base->flags) & 0x3e0) == 0) {
    pcVar1 = type_function_return(fn_type);
    pcVar2 = type_function_return(base_fn_type);
    if (((pcVar1 == pcVar2) || ((pcVar1->code & 0x800) != 0)) || ((pcVar2->code & 0x800) != 0)) {
      if ((((byte)base_fn_type->flags ^ (byte)fn_type->flags) & 7) != 0) {
        if (report == '\0') {
          return '\0';
        }
        diag_error(0x22b,cls,&fn[-1].position,
                   g_scope_vector->entries[*(short *)((int)&base_fn[-1].type + 2)],
                   &base_fn[-1].position);
      }
      return '\x01';
    }
    if (report != '\0') {
      diag_error(0x22b,cls,&fn[-1].position,
                 g_scope_vector->entries[*(short *)((int)&base_fn[-1].type + 2)],
                 &base_fn[-1].position);
      return '\x01';
    }
  }
  return '\0';
}

