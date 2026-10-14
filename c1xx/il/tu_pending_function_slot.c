int __cdecl tu_pending_function_slot(uint slot)

{
  return (&g_pending_destructor_helpers)[slot & 0xff];
}

