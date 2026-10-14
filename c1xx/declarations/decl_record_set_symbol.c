void __thiscall decl_record_set_symbol(void *this,c1_symbol *sym)

{
  *(c1_symbol **)((int)this + 0x38) = sym;
  return;
}

