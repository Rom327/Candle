﻿#ifndef SHADERDRAWABLE_H
#define SHADERDRAWABLE_H

#include <QObject>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

struct VertexData
{
    QVector3D position;
    QVector3D color;
    QVector3D start;
};

class ShaderDrawable : protected QOpenGLFunctions
{
public:
    explicit ShaderDrawable();
    ~ShaderDrawable();
    void update();
    void draw(QOpenGLShaderProgram *shaderProgram);

    bool needsUpdateGeometry() const;
    void updateGeometry(QOpenGLShaderProgram *shaderProgram = 0);

    virtual QVector3D getSizes();
    virtual QVector3D getMinimumExtremes();
    virtual QVector3D getMaximumExtremes();
    virtual int getVertexCount();

    double lineWidth() const;
    void setLineWidth(double lineWidth);

    bool visible() const;
    void setVisible(bool visible);

    double pointSize() const;
    void setPointSize(double pointSize);

signals:

public slots:

protected:
    double m_lineWidth;
    double m_pointSize;
    bool m_visible;
    QVector<VertexData> m_lines;
    QVector<VertexData> m_points;

    virtual void updateData();

private:
    QOpenGLBuffer m_vbo;
    QOpenGLVertexArrayObject m_vao;

    bool m_needsUpdateGeometry;

    void init();
};

#endif // SHADERDRAWABLE_H
