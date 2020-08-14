#ifndef GLHPP_RENDERBUFFER_HPP
#define GLHPP_RENDERBUFFER_HPP

#include "Object.hpp"


namespace gl
{
	class Renderbuffer: public impl::DefaultableObject<Renderbuffer>
	{
	protected:
		Renderbuffer(impl::NullInitializerFlagType) {}
	public:
		Renderbuffer(GLenum target)
		{
			id=0;
			glCreateRenderbuffers(1,&id);
			deleter_func=glDeleteRenderbuffers;
			is_func=glIsRenderbuffer;
		}
		
		void Bind(GLenum target) const
		{
			glBindRenderbuffer(target,id);
		}
		
		void StorageMultisample(GLsizei samples,GLenum internalformat,GLsizei width,GLsizei height)
		{
			glNamedRenderbufferStorageMultisample(id,samples,internalformat,width,height);
		}
		void Storage(GLenum internalformat,GLsizei width,GLsizei height)
		{
			glNamedRenderbufferStorage(id,internalformat,width,height);
		}
		void GetParameter(GLenum pname,GLint* params) const
		{
			glGetNamedRenderbufferParameteriv(id,pname,params);
		}
		#ifndef GLHPP_STRICT_API
		GLint GetParameter(GLenum pname) const
		{
			GLint z;GetParameter(pname,&z);
			return z;
		}
		#endif
		
	};
}

#endif
