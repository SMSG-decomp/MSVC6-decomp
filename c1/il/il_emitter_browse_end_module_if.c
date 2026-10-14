void __thiscall il_emitter_browse_end_module_if(c1_il_emitter_browse *this,int force)

{
  if ((g_emitter_region_mode != 2) || (force != 0)) {
    (*this->vtbl->end_module)();
  }
  return;
}

