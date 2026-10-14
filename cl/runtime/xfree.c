void __cdecl xfree(void *p)

{
  if (p != (void *)0x0) {
    free(p);
  }
  return;
}

